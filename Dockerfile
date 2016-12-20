FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
   build-essential \
   check \
   git \
   valgrind \
   pkg-config

CMD ["/bin/bash"]
