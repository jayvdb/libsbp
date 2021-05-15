# Copyright (C) 2020 Swift Navigation Inc.
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

FROM ubuntu:bionic

ARG DEBIAN_FRONTEND=noninteractive

ARG DOCKER_UID=1000
ARG DOCKER_USER=dockerdev

ENV NODE_VERSION=v12.22.0

ENV RUSTUP_HOME=/rust
ENV CARGO_HOME=/cargo

ENV PATH=/usr/lib/ccache:/cargo/bin:/rust/bin:${PATH}

RUN \
     apt-get update \
  && apt-get install -y \
      git \
      sudo \
      software-properties-common \
      apt-utils \
      wget \
      make

RUN addgroup "$DOCKER_USER"
RUN useradd -m -u $DOCKER_UID -G $DOCKER_USER,sudo -s "/bin/bash" $DOCKER_USER
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers

WORKDIR /mnt/workspace
USER $DOCKER_USER

CMD ["make", "all"]

# vim: ft=dockerfile
