FROM ubuntu:16.04
MAINTAINER Biswadip Maity <biswadip.maity@gmail.com>

# get dependencies
RUN apt-get update
RUN apt-get install -y build-essential libssl-dev git-core python-dev python \
    g++-arm-linux-gnueabihf gcc-arm-none-eabi bc sshpass vim
RUN apt-get clean

RUN mkdir -p /workspace
WORKDIR /workspace

RUN git clone https://github.com/juhda/sparta -b odroidxu4-4.14.y
RUN git clone --depth 1 https://github.com/hardkernel/linux -b odroidxu4-4.14.y

ENTRYPOINT bash
WORKDIR /workspace/linux
RUN cp /workspace/sparta/docker/build.bash /workspace/linux
RUN chmod ugo+x build.bash
RUN ./build.bash

WORKDIR /workspace/sparta
RUN sed -i '0,/=host/s//=arm/' .makefile.buildopts
RUN make -j4 daemons lin_sensing_module ubench
