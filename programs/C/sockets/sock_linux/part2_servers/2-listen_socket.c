/*
 * After binding a socket to a port the next thinf we need to do is listen for connections.
 * For this we need to put the socket in listening mode. FUnction listen() is used to put the
 * socket in listening mode.
 * Just add the following line after bind.
 *
 */
listen(socket_desc, 3);

// Thats all. Now comes the main part of accepting new connections.
