Installing and running CCheck
> git clone https://github.com/imnadev/c-check.git

> cd main

> sudo dnf install gtk3-devel gstreamer1-devel clutter-devel webkit2gtk3-devel libgda-devel gobject-introspection-devel

> gcc -export-dynamic -Wall main.c ../database/database.c ../screen/server/server_window.c ../screen/client/client_window.c ../screen/setup/setup_window.c ../screen/result/result_window.c ../socket/client/client.c ../socket/server/server.c -o CCheck -pthread \`pkg-config --cflags --libs gtk+-3.0\` && ./CCheck
