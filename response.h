#ifndef M2X_RESPONSE_H
#define M2X_RESPONSE_H

#include "m2x.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct m2x_response {
  int status;

  /* This is the raw response from the server. It is managed by m2x
   * context, you don't need to free it. However, it is only valid
   * before the next m2x API call.
   * NOTE: This buffer is not necessarily NULL-terminated.
   */
  char *raw;
  int raw_length;

  /* This is generated by plugged-in JSON parsers, it is very likely
   * you will need to free this manually(depending on the specific
   * JSON parser in use).
   */
  void *data;
} m2x_response;

int m2x_is_success(const m2x_response *response);
int m2x_is_client_error(const m2x_response *response);
int m2x_is_server_error(const m2x_response *response);
int m2x_is_error(const m2x_response *response);
void m2x_release_response(m2x_context *ctx, m2x_response *response);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_H */
