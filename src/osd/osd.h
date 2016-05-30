#ifndef CCEPH_OSD_OSD_H
#define CCEPH_OSD_OSD_H

#include "message/messenger.h"
#include "message/server_messenger.h"
#include "message/msg_header.h"

#include "os/object_store.h"

typedef struct {
    cceph_osd_id_t          osd_id;

    cceph_object_store*     os;
    cceph_os_funcs*         os_funcs;

    cceph_messenger*        msger;
    cceph_server_messenger* smsger;
} cceph_osd;

extern int cceph_osd_initial(
        cceph_osd**         osd,
        cceph_osd_id_t      osd_id,
        cceph_object_store* os,
        cceph_os_funcs*     os_funcs,
        int64_t             log_id);

extern int cceph_osd_create(
        cceph_osd* osd,
        int64_t    log_id);

extern int cceph_osd_start(
        cceph_osd* osd,
        int64_t    log_id);

extern int cceph_osd_process_message(
        cceph_messenger* cceph_messenger,
        cceph_conn_id_t conn_id,
        cceph_msg_header* message,
        void* context);

#endif
