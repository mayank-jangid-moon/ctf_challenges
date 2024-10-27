FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat
RUN useradd -ms /bin/sh ctf_player
RUN mkdir /app
COPY chall /app
COPY flag.txt /app

WORKDIR /app

EXPOSE 6969

CMD ["socat", "-T60", "TCP-LISTEN:6969,reuseaddr,fork,su=ctf_player","EXEC:/app/chall"]
