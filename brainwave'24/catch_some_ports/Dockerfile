FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat python3
RUN useradd -ms /bin/sh ctf_player

RUN mkdir /app
COPY app.py /app

WORKDIR /app

EXPOSE 37824

CMD ["socat", "-T60", "TCP-LISTEN:37824,reuseaddr,fork,su=ctf_player", "EXEC:python3 /app/app.py"]

