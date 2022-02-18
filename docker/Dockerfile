FROM amd64/alpine:3.15

RUN apk update && \
    apk add build-base && \
    apk add libgcc && \
    apk add libstdc++ && \
    apk add gcompat && \
    apk add libc6-compat && \
    apk add musl && \
    apk add cmake && \
    apk add curl && \
    apk add git && \
    apk add tar

ARG ARM_TOOLCHAIN_URL=https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
ARG ARM_TOOLCHAIN_DIR=/opt
ARG ARM_TOOLCHAIN_NAME=gcc-arm-none-eabi-10.3-2021.10

WORKDIR ${ARM_TOOLCHAIN_DIR}
RUN curl -sL ${ARM_TOOLCHAIN_URL} --output ${ARM_TOOLCHAIN_NAME}.tar.bz2
RUN tar -xf ${ARM_TOOLCHAIN_NAME}.tar.bz2 && rm -rf ${ARM_TOOLCHAIN_NAME}.tar.bz2

#RUN addgroup -S arm && adduser -S arm -G arm
#USER arm


#WORKDIR /home/arm
ENV PATH $PATH:/opt/${ARM_TOOLCHAIN_NAME}/bin
ENTRYPOINT [ "/bin/sh", "-c" ]
