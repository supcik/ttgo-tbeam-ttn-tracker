#ifndef LIB_TTN_TTN_H_
#define LIB_TTN_TTN_H_

#include <Arduino.h>

void ttn_register(void (*callback)(uint8_t message));
size_t ttn_response_len();
void ttn_response(uint8_t* buffer, size_t len);
bool ttn_setup();
void ttn_join();
void ttn_sf(unsigned char sf);
void ttn_adr(bool enabled);
uint32_t ttn_get_count();
void ttn_erase_prefs();
void ttn_send(uint8_t* data, uint8_t data_size, uint8_t port, bool confirmed);
void ttn_loop();

#endif /* LIB_TTN_TTN_H_ */
