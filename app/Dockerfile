FROM ubuntu:20.04

# install vscode (code-server)
WORKDIR /works
COPY ./build_resource/code-server-3.0.0-linux-x86_64.tar.gz /works/code-server-3.0.0-linux-x86_64.tar.gz
RUN tar -xzf code-server-3.0.0-linux-x86_64.tar.gz -C ./ --strip-components 1
RUN /works/code-server --install-extension ms-vscode.cpptools

# install C
WORKDIR /works
RUN apt-get update
RUN apt-get install -y wget gnupg1
RUN apt-get install musl-dev -y
RUN apt-get install build-essential -y
RUN apt-get install cmake -y 
RUN apt-get install python3 -y

# install embedtls
COPY ./build_resource/mbedtls-2.16.5-apache.tgz /works/mbedtls-2.16.5-apache.tgz
RUN tar zxf mbedtls-2.16.5-apache.tgz
WORKDIR /works/mbedtls-2.16.5/build
RUN cmake ..
RUN make
RUN make install

CMD ["/works/code-server", "--auth","none", "--host","0.0.0.0","--port","8443", "/app"]