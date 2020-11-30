/**************************************************************************
 *
 * Copyright (C) 2020 Chromium.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#ifndef VIRGL_CONTEXT_H
#define VIRGL_CONTEXT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "virgl_resource.h"

struct vrend_transfer_info;
struct pipe_resource;

struct virgl_context_blob {
   /* valid fd or pipe resource */
   enum virgl_resource_fd_type type;
   union {
      int fd;
      struct pipe_resource *pipe_resource;
   } u;

   void *renderer_data;
};

/**
 * Base class for renderer contexts.  For example, vrend_decode_ctx is a
 * subclass of virgl_context.
 */
struct virgl_context {
   uint32_t ctx_id;

   void (*destroy)(struct virgl_context *ctx);

   void (*attach_resource)(struct virgl_context *ctx,
                           struct virgl_resource *res);
   void (*detach_resource)(struct virgl_context *ctx,
                           struct virgl_resource *res);

   int (*transfer_3d)(struct virgl_context *ctx,
                      struct virgl_resource *res,
                      const struct vrend_transfer_info *info,
                      int transfer_mode);

   /* These are used to create a virgl_resource from a context object.
    *
    * get_blob returns a virgl_context_blob from which a virgl_resource can be
    * created.  get_blob_done is optional and allows the context to associate
    * the newly created resource with the context object.
    *
    * Note that get_blob is a one-time thing.  The context object might be
    * destroyed or reject subsequent get_blob calls.
    */
   int (*get_blob)(struct virgl_context *ctx,
                   uint64_t blob_id,
                   uint32_t blob_flags,
                   struct virgl_context_blob *blob);
   void (*get_blob_done)(struct virgl_context *ctx,
                         uint32_t res_id,
                         struct virgl_context_blob *blob);

   int (*submit_cmd)(struct virgl_context *ctx,
                     const void *buffer,
                     size_t size);
};

struct virgl_context_foreach_args {
   bool (*callback)(struct virgl_context *ctx, void *data);
   void *data;
};

int
virgl_context_table_init(void);

void
virgl_context_table_cleanup(void);

void
virgl_context_table_reset(void);

int
virgl_context_add(struct virgl_context *ctx);

void
virgl_context_remove(uint32_t ctx_id);

struct virgl_context *
virgl_context_lookup(uint32_t ctx_id);

void
virgl_context_foreach(const struct virgl_context_foreach_args *args);

#endif /* VIRGL_CONTEXT_H */
