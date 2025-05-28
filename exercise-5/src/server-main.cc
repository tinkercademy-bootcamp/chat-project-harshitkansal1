#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "net/chat-sockets.h"
#include "utils.h"

namespace tt::chat::server {
class Server {
  private:
  int kPort;
  int socket;
  sockaddr_in address;

  void handle_accept(int sock) {
  namespace ttc = tt::chat;
  const int kBufferSize = 1024;
  char buffer[kBufferSize] = {0};
  ssize_t read_size = read(sock, buffer, kBufferSize);

  ttc::check_error(read_size < 0,
                   "Read error on client socket " + std::to_string(sock));
  if (read_size > 0) {
    std::cout << "Received:" << buffer << "\n";
    send(sock, buffer, read_size, 0);
    std::cout << "Echo message sent\n";
  } else if (read_size == 0) {
    std::cout << "Client disconnected.\n";
  } else {
    std::cerr << "Read error on client socket " << sock << "\n";
  }
  close(sock);
}

  public:
  Server(int kport) {
    kPort = kport;
  }

void set_socket_options(int opt) {
  namespace ttc = tt::chat;
  auto err_code = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                             &opt, sizeof(opt));
  ttc::check_error(err_code < 0, "setsockopt() error\n");
}
void create_server_socket() {
  socket = net::create_socket();
  set_socket_options( 1);
}
void bind_address_to_socket() {
  namespace ttc = tt::chat;
  auto err_code = bind(socket, (sockaddr *)&address, sizeof(address));
  ttc::check_error(err_code < 0, "bind failed\n");
}

void listen_on_socket() {
  namespace ttc = tt::chat;
  auto err_code = listen(socket, 3);
  ttc::check_error(err_code < 0, "listen failed\n");
}


void create_server_address() {
  namespace ttn = tt::chat::net;
  address = ttn::create_address(kPort);
  address.sin_addr.s_addr = INADDR_ANY;
}

void handle_connections() {
  socklen_t address_size = sizeof(address);

  while (true) {
    int accepted_socket = accept(socket, (sockaddr *)&address, &address_size);
    tt::chat::check_error(accepted_socket < 0, "Accept error n ");
    handle_accept(accepted_socket);
  }
}

 ~Server() {
    if (socket >= 0) {
      close(socket);
      std::cout << "Server socket closed.\n";
    }
  }

};

} // namespace tt::chat::server

int main() {
  namespace ttc = tt::chat;
  const int kPort = 8080;

  ttc::server::Server myserver(kPort);
  myserver.create_server_socket();
  myserver.create_server_address();

  // start listening on the socket
  myserver.bind_address_to_socket();
  myserver.listen_on_socket();

  std::cout << "Server listening on port " << kPort << "\n";
  myserver.handle_connections();

  return 0;
}
