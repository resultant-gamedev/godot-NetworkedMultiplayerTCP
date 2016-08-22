#include "os/os.h"
#include "io/marshalls.h"
#include "networked_multiplayer_tcp.h"

int NetworkedMultiplayerTCP::get_packet_peer() const {

  // TODO

  return 0;  // STUB
}

uint32_t NetworkedMultiplayerTCP::_gen_unique_id() const {

  uint32_t hash = 0;

  while( hash == 0 || hash == 1 ) {
    hash = hash_djb2_one_32( (uint32_t) OS::get_singleton()->get_ticks_usec() );
    hash = hash_djb2_one_32( (uint32_t) OS::get_singleton()->get_unix_time(), hash );
    hash = hash_djb2_one_32( (uint32_t) OS::get_singleton()->get_data_dir().hash64(), hash );
    hash = hash_djb2_one_32( (uint32_t) ((uint64_t) this), hash );
    hash = hash_djb2_one_32( (uint32_t) ((uint64_t) &hash), hash );
    hash = hash&0x7FFFFFFF;
  }

  return hash;
}

int NetworkedMultiplayerTCP::get_unique_id() const {

  return unique_id;
}

bool NetworkedMultiplayerTCP::is_refusing_new_connections() const {

  return refuse_connections;
}

void NetworkedMultiplayerTCP::poll() {
  // TODO
}


void NetworkedMultiplayerTCP::set_refuse_new_connections(bool p_enable) {
  refuse_connections = p_enable;
}


void NetworkedMultiplayerTCP::set_target_peer(int p_peer) {
  target_peer = p_peer;
}

void NetworkedMultiplayerTCP::set_transfer_mode(TransferMode p_mode) {
  transfer_mode = p_mode;
}

NetworkedMultiplayerPeer::ConnectionStatus NetworkedMultiplayerTCP::get_connection_status() const {
  return connection_status;
}

void NetworkedMultiplayerTCP::_bind_methods() {
  // TODO
}

NetworkedMultiplayerTCP::NetworkedMultiplayerTCP() {
  refuse_connections = false;
  unique_id = _gen_unique_id();
  target_peer = 0;
  transfer_mode = TRANSFER_MODE_RELIABLE;
  connection_status = CONNECTION_DISCONNECTED;
}

NetworkedMultiplayerTCP::~NetworkedMultiplayerTCP() {
  // TODO
}
