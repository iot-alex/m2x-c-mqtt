#include <curl/curl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "m2x.h"

m2x_context *m2x_open(const char* key)
{
  m2x_context *ctx;
  ctx = (m2x_context *) m2x_malloc(NULL, sizeof(m2x_context));
  memset(ctx, 0, sizeof(m2x_context));

  ctx->verbose = 0;
  ctx->key = m2x_malloc(ctx, strlen(key) + 1);
  strcpy(ctx->key, key);
  return ctx;
}

void m2x_close(m2x_context *ctx)
{
  m2x_free(ctx->key);
  m2x_free(ctx);
}

void m2x_set_verbose(m2x_context *ctx, int verbose)
{
  if (ctx) {
    ctx->verbose = verbose;
  }
}

void *m2x_malloc(m2x_context *ctx, size_t len)
{
  return m2x_realloc(ctx, NULL, len);
}

void *m2x_realloc(m2x_context *ctx, void *p, size_t len)
{
  void *p2;

  p2 = realloc(p, len);
  if (!p2) {
    /* Not enough memory */
    m2x_close(ctx);
    exit(ENOMEM);
  }
  return p2;
}

void m2x_free(void *p)
{
  if (p) {
    free(p);
  }
}