FROM python:3.8-alpine

RUN mkdir /app
COPY app.py /app
COPY db.py /app
COPY templates/ /app/
RUN chmod +x /app/app.py

RUN pip install flask
WORKDIR /app
RUN mkdir templates && mv index.html templates

CMD ["python3","/app/app.py"]
