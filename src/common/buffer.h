#ifndef CCEPH_BUFFER_H
#define CCEPH_BUFFER_H

#include "common/types.h"

#define CCEPH_BUFFER_NODE_LENGTH 4096

typedef struct cceph_buffer_node_ cceph_buffer_node_;
struct cceph_buffer_node_ {
    cceph_buffer_node_ *next;
    char*   ptr;     //Pointer to current write position
    int32_t length;  //Node memory length
    char   data[CCEPH_BUFFER_NODE_LENGTH]; //Real data
};
typedef cceph_buffer_node_ cceph_buffer_node;

typedef struct {
    cceph_buffer_node* head;
    cceph_buffer_node* current;

    int32_t length;
    int32_t offset;
} cceph_buffer;

extern int cceph_buffer_new(
        cceph_buffer** buffer,
        int64_t        log_id);

extern int cceph_buffer_free(
        cceph_buffer** buffer,
        int64_t        log_id);

extern int cceph_buffer_append(
        cceph_buffer* buffer,
        char*         data,
        int32_t       length,
        int64_t       log_id);

typedef struct {
    cceph_buffer*      buffer;
    cceph_buffer_node* node;
    char*              ptr;
} cceph_buffer_reader;

#endif