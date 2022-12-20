Installing and running CCheck
> git clone https://github.com/imnadev/c-check.git

> cd main

> gcc -export-dynamic -Wall main.c ../database/database.c ../screen/server/server_window.c ../screen/client/client_window.c ../screen/setup/setup_window.c ../socket/client/client.c ../socket/server/server.c -o CCheck -pthread \`pkg-config --cflags --libs gtk+-3.0\` && ./CCheck