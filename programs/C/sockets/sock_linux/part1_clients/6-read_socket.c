// When receiving data on a socket, we are basically reading the data on the socket. THis is similar to
// reading data from a file. So we can also use the read() function to read data on a socket. For example:
read(socket_desc, server_reply, 2000);
