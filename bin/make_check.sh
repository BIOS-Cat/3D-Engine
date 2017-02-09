${docker_image:=bios-cat}

docker run -P -v $PWD:/src $docker_image /bin/sh -c 'cd src && make && make check'
