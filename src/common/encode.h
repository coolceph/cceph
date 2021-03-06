#ifndef CCEPH_ENCODE_H
#define CCEPH_ENCODE_H

#include "common/buffer.h"

#define CCEPH_DEFINE_BASIC_ENCODE_METHOD(type)   \
    extern int cceph_encode_##type(              \
            cceph_buffer* buffer,                \
            type          value,                 \
            int64_t       log_id);               \
    extern int cceph_decode_##type(              \
            cceph_buffer_reader* reader,         \
            type*                value,          \
            int64_t              log_id);        \

#define CCEPH_DEFINE_ENCODE_METHOD(type)         \
extern int cceph_encode_##type(                  \
        cceph_buffer* buffer,                    \
        cceph_##type* value,                     \
        int64_t       log_id);                   \
extern int cceph_decode_##type(                  \
        cceph_buffer_reader* reader,             \
        cceph_##type*        value,              \
        int64_t              log_id);            \

CCEPH_DEFINE_BASIC_ENCODE_METHOD(char);
CCEPH_DEFINE_BASIC_ENCODE_METHOD(int);
CCEPH_DEFINE_BASIC_ENCODE_METHOD(int8_t);
CCEPH_DEFINE_BASIC_ENCODE_METHOD(int16_t);
CCEPH_DEFINE_BASIC_ENCODE_METHOD(int32_t);
CCEPH_DEFINE_BASIC_ENCODE_METHOD(int64_t);

#define cceph_encode_int8(buffer, value, log_id)    \
        cceph_encode_int8_t(buffer, value, log_id)
#define cceph_decode_int8(reader, value, log_id)    \
        cceph_decode_int8_t(reader, value, log_id)

#define cceph_encode_int16(buffer, value, log_id)    \
        cceph_encode_int16_t(buffer, value, log_id)
#define cceph_decode_int16(reader, value, log_id)    \
        cceph_decode_int16_t(reader, value, log_id)

#define cceph_encode_int32(buffer, value, log_id)    \
        cceph_encode_int32_t(buffer, value, log_id)
#define cceph_decode_int32(reader, value, log_id)    \
        cceph_decode_int32_t(reader, value, log_id)

#define cceph_encode_int64(buffer, value, log_id)    \
        cceph_encode_int64_t(buffer, value, log_id)
#define cceph_decode_int64(reader, value, log_id)    \
        cceph_decode_int64_t(reader, value, log_id)

#define cceph_encode_version(buffer, value, log_id) \
        cceph_encode_int8(buffer, value, log_id)
#define cceph_decode_version(reader, value, log_id) \
        cceph_decode_int8(reader, value, log_id)

#define cceph_encode_epoch(buffer, value, log_id) \
        cceph_encode_int32(buffer, value, log_id)
#define cceph_decode_epoch(reader, value, log_id) \
        cceph_decode_int32(reader, value, log_id)

extern int cceph_encode_string(
        cceph_buffer*        buffer,
        char*                value,
        int64_t              log_id);
extern int cceph_decode_string(
        cceph_buffer_reader* reader,
        char**               value,
        int64_t              log_id);

#endif
