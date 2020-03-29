get_buffer = function(index, len) {
    console.log("--a--")
    console.log(index);
    console.log(len);
    var v =  new Uint8Array(Module.HEAP8.buffer, index, len);
    console.log("--b--")
    return v;
  }