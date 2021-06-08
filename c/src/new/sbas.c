#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/sbas.h>
#include <libsbp/internal/new/sbas.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->message_type);
  packed_size += ( 27 * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

bool encode_sbp_msg_sbas_raw_t(sbp_encode_ctx_t *ctx, const sbp_msg_sbas_raw_t *msg)
{
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!encode_u32(ctx, &msg->tow)) { return false; }
  if (!encode_u8(ctx, &msg->message_type)) { return false; }
  for (uint8_t i = 0; i < 27; i++)
  {
    if (!encode_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_sbas_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_sbas_raw_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_sbas_raw_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_sbas_raw_t(sbp_decode_ctx_t *ctx, sbp_msg_sbas_raw_t *msg)
{
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!decode_u32(ctx, &msg->tow)) { return false; }
  if (!decode_u8(ctx, &msg->message_type)) { return false; }
  for (uint8_t i = 0; i < 27; i++) {
    if (!decode_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_sbas_raw_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_sbas_raw_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_sbas_raw_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_sbas_raw_t(struct sbp_state *s, u16 sender_id, const sbp_msg_sbas_raw_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_sbas_raw_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_SBAS_RAW, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *a, const sbp_msg_sbas_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->message_type, &b->message_type);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 27 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
