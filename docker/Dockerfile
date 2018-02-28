FROM ubuntu:16.04
MAINTAINER Biswadip Maity <biswadip.maity@gmail.com>

# get dependencies
RUN apt-get update
RUN apt-get install -y build-essential git-core python-dev python vim \
    g++-arm-linux-gnueabihf gcc-arm-none-eabi bc sshpass dos2unix
RUN apt-get clean

RUN mkdir -p /workspace
WORKDIR /workspace

RUN git clone https://github.com/juhda/sparta -b odroidxu3-3.10.y
RUN git clone --depth 1 https://github.com/hardkernel/linux -b odroidxu3-3.10.y

ENTRYPOINT bash
WORKDIR /workspace/linux
ADD build.bash /workspace/linux
RUN dos2unix build.bash
RUN chmod ugo+x build.bash
RUN ./build.bash

WORKDIR /workspace/sparta
RUN sed -i '0,/=host/s//=arm/' .makefile.buildopts
RUN make -j4 daemons lin_sensing_module ubench
