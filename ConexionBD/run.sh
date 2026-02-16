#!/bin/bash

echo "Compilando..."
g++ coBD.cpp -o coBD -lmysqlcppconn || exit 1

echo "Ejecutando..."
./coBD
