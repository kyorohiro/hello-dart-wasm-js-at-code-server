FROM ubuntu:20.04

# install vscode (code-server)
WORKDIR /works
COPY ./build_resource/code-server-3.0.0-linux-x86_64.tar.gz /works/code-server-3.0.0-linux-x86_64.tar.gz
RUN tar -xzf code-server-3.0.0-linux-x86_64.tar.gz -C ./ --strip-components 1
RUN /works/code-server --install-extension ms-vscode.cpptools

# install C (emcc)
WORKDIR /works
RUN apt-get update
RUN apt-get install -y wget gnupg1
RUN apt-get install -y git
RUN apt-get install python3 -y
RUN apt-get install python3-pip -y
RUN ln -s `which pip3` /usr/bin/pip 
RUN ln -s `which python3` /usr/bin/python 
WORKDIR /works/wasm
RUN git clone https://github.com/emscripten-core/emsdk.git

WORKDIR /works/wasm/emsdk
RUN ./emsdk install latest
RUN ./emsdk activate latest
ENV PATH=${PATH}:/works/wasm/emsdk:/works/wasm/emsdk/node/12.9.1_64bit/bin:/works/wasm/emsdk/upstream/emscripten
#RUN source /works/wasm/emsdk/emsdk_env.sh --build=Release
RUN apt install -y nodejs npm


# install embedtls
WORKDIR /works
COPY ./build_resource/mbedtls-2.16.5-apache.tgz /works/mbedtls-2.16.5-apache.tgz
RUN tar zxf mbedtls-2.16.5-apache.tgz
WORKDIR /works/mbedtls-2.16.5
RUN emmake make


CMD ["/works/code-server", "--auth","none", "--host","0.0.0.0","--port","8443", "/app"]