# Copyright (C) 2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

# This describes an image that should be able to generate libsbp bindings.
# See the README.md for instructions on how to use it.

FROM ubuntu:focal

ARG DEBIAN_FRONTEND=noninteractive

ENV NODE_VERSION=v14.17.3
ENV JAVA_VERSION=11.0.11.hs-adpt
ENV GRADLE_VERSION=7.1.1
ENV CC=gcc-7
ENV CXX=g++-7

ENV RUSTUP_HOME=/rust
ENV CARGO_HOME=/cargo

ENV SDKMAN_DIR=/opt/sdkman

ENV PATH=/usr/lib/ccache:/cargo/bin:/rust/bin:${PATH}

RUN \
     apt-get update \
  && apt-get install -y --no-install-recommends \
      git \
      sudo \
      software-properties-common \
      apt-utils \
      wget \
      curl \
      gnupg netbase \
      libudev-dev \
      uuid-dev \
      libffi-dev \
      libgmp-dev \
      zlib1g-dev \
      zip unzip \
      build-essential \
      $CC $CXX \
      pandoc \
      llvm \
      clang \
      texlive-fonts-extra \
      texlive-latex-extra \
      texlive-science \
      check \
      ccache \
      pkg-config \
      doxygen \
      graphviz \
      imagemagick \
      clang-format-6.0 \
  && rm -rf /var/lib/apt/lists/* /tmp/* \
  && find /usr/lib/python*/ \
    \( -name 'test' -o -name 'tests' -o -name 'test_*' -o \
       -name '*.pyc' -o -name '*.pyo' \
    \) -prune -exec rm -rf '{}' '+' \
  && curl -s "https://get.sdkman.io" | bash \
  && bash -c "source $SDKMAN_DIR/bin/sdkman-init.sh; \
              sdk install java $JAVA_VERSION; sdk install gradle $GRADLE_VERSION; \
	      which java; which gradle"

ENV PATH=${SDKMAN_DIR}/candidates/java/current/bin:${PATH}
ENV PATH=${SDKMAN_DIR}/candidates/gradle/current/bin:${PATH}

RUN \
     java --version \
  && gradle --version \
  && add-apt-repository ppa:deadsnakes/ppa \
  && apt-get update \
  && apt-get install -y --no-install-recommends \
      libpython2.7-stdlib \
      libpython3.8-stdlib \
      python-is-python3 \
      python3-pip \
      python3.5 \
      python3.6 \
      python3.7\
      python3.9 \
  && pip3 install tox sphinx tox-run-command \
  && rm -rf /var/lib/apt/lists/* /tmp/* \
  && find /usr/lib/python*/ \
    \( -name 'test' -o -name 'tests' -o -name 'test_*' -o \
       -name '*.pyc' -o -name '*.pyo' \
    \) -prune -exec rm -rf '{}' '+' \
  && curl https://sh.rustup.rs -sSf | sh -s -- -y --default-toolchain stable --profile minimal --no-modify-path \
  && rustup component add rustfmt \
  && curl -sSL https://get.haskellstack.org/ | sh

ARG KITWARE_KEY_URL=https://apt.kitware.com/keys/kitware-archive-latest.asc

RUN \
     wget -O - ${KITWARE_KEY_URL} 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
  && add-apt-repository 'deb https://apt.kitware.com/ubuntu/ focal main' \
  && apt-get update \
  && apt-get install -y --no-install-recommends \
    cmake \
  && rm -rf /var/lib/apt/lists/* /tmp/*

ENV NVM_DIR=/opt/nvm

RUN \
     mkdir -p $NVM_DIR \
  && curl -sL https://raw.githubusercontent.com/creationix/nvm/v0.38.0/install.sh | bash \
  && . $NVM_DIR/nvm.sh \
  && nvm install $NODE_VERSION

ENV NODE_PATH=$NVM_DIR/versions/node/$NODE_VERSION/lib/node_modules
ENV PATH=$NVM_DIR/versions/node/$NODE_VERSION/bin:${PATH}

RUN npm install npm@latest mocha quicktype -g

ARG UID=1000

# Add a "dockerdev" user with sudo capabilities
# 1000 is the first user ID issued on Ubuntu; might
# be different for Mac users. Might need to add more.
RUN \
     useradd -u ${UID} -ms /bin/bash -G sudo dockerdev \
  && echo '%sudo ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers \
  && find $NVM_DIR -exec chmod a+rw {} \; \
  && find $RUSTUP_HOME -exec chmod a+rw {} \; \
  && find $CARGO_HOME -exec chmod a+rw {} \;

WORKDIR /mnt/workspace
USER dockerdev

RUN stack install --resolver lts-10.10 sbp \
  && rm -rf /tmp/* \
  && if [ "$(ls /tmp)" ]; then false; fi

CMD ["make", "all"]

# vim: ft=dockerfile
