#ifndef NETWORKED_MULTIPLAYER_TCP_H
#define NETWORKED_MULTIPLAYER_TCP_H

#include "io/networked_multiplayer_peer.h"
#include "io/stream_peer_tcp.h"

class NetworkedMultiplayerTCP : public NetworkedMultiplayerPeer, public PacketPeerStream {

  OBJ_TYPE( NetworkedMultiplayerTCP, NetworkedMultiplayerPeer )
  //OBJ_TYPE( NetworkedMultiplayerTCP, PacketPeerStream );

protected:
  static void _bind_methods();
public:

  void set_transfer_mode(TransferMode p_mode);
  void set_target_peer(int p_peer_id);

  int get_packet_peer() const;

  bool is_server() const;

  void poll();

  int get_unique_id() const;

  void set_refuse_new_connections(bool p_enable);
  bool is_refusing_new_connections() const;

  ConnectionStatus get_connection_status() const;

  NetworkedMultiplayerTCP();
  ~NetworkedMultiplayerTCP();

  Error create_client(const IP_Address& p_ip, int p_port);

private:
  bool active;
  uint32_t unique_id;
  int target_peer;
  TransferMode transfer_mode;
  bool refuse_connections;
  ConnectionStatus connection_status;
  uint32_t _gen_unique_id() const;

  Ref<StreamPeerTCP> stream_peer;
};


#endif  // NETWORKED_MULTIPLAYER_TCP_H
