#!/bin/bash
# My job's description
#PBS -l nodes=1:ppn=16
#PBS -l walltime=02:00:00
#PBS -N Austin_Wade_Matrix
#PBS -m bea
#PBS -M wawade42@students.tntech.edu
cd ~/parallel_programming/assignment_2/

echo "*****serial*****" >> matrix_runs.txt
./serial a.txt b.txt out-s.txt >> matrix_runs.txt

echo "*****parallel-1*****" >> matrix_runs.txt
./parallel --threads 1 a.txt b.txt out-p1.txt >> matrix_runs.txt

echo "*****parallel-2*****" >> matrix_runs.txt
./parallel --threads 2 a.txt b.txt out-p2.txt >> matrix_runs.txt

echo "*****parallel-4*****" >> matrix_runs.txt
./parallel --threads 4 a.txt b.txt out-p4.txt >> matrix_runs.txt

echo "*****parallel-8*****" >> matrix_runs.txt
./parallel --threads 8 a.txt b.txt out-p8.txt >> matrix_runs.txt

echo "*****parallel-16*****" >> matrix_runs.txt
./parallel --threads 16 a.txt b.txt out-p16.txt >> matrix_runs.txt
