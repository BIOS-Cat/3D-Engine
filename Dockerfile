FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
   build-essential \
   curl \
   libglu1-mesa-dev \
   freeglut3-dev \
   mesa-common-dev \
   autoconf \
   libtool \
   git \
   valgrind \
   pkg-config

RUN curl -sL https://github.com/libcheck/check/releases/download/0.11.0/check-0.11.0.tar.gz | tar xz

RUN cd check-0.11.0 && autoreconf --install && ./configure && make && make install && cd ..

RUN curl -sL https://libsdl.org/release/SDL2-2.0.5.tar.gz | tar xz 

RUN cd SDL2-2.0.5 && ./configure && make && make install

RUN ldconfig

CMD ["/bin/bash"]
