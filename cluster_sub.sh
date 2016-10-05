#!/bin/bash
# My job's description
#PBS -l nodes=1:ppn=16
#PBS -l walltime=010:00:00
#PBS -N Austin_Wade_Matrix
#PBS -m bea
#PBS -M wawade42@students.tntech.edu
cd ~/parallel_programming/assignment_2/

echo "*****serial-1000*****" >> matrix_runs.txt
./serial a1000.txt b1000.txt c1000-s.txt >> matrix_runs.txt

echo "*****parallel-1-1000*****" >> matrix_runs.txt
./parallel --threads 1 a1000.txt b1000.txt c1000-p1.txt >> matrix_runs.txt

echo "*****parallel-2-1000*****" >> matrix_runs.txt
./parallel --threads 2 a1000.txt b1000.txt c1000-p2.txt >> matrix_runs.txt

echo "*****parallel-4-1000*****" >> matrix_runs.txt
./parallel --threads 4 a1000.txt b1000.txt c1000-p4.txt >> matrix_runs.txt

echo "*****parallel-8-1000*****" >> matrix_runs.txt
./parallel --threads 8 a1000.txt b1000.txt c1000-p8.txt >> matrix_runs.txt

echo "*****parallel-16-1000*****" >> matrix_runs.txt
./parallel --threads 16 a1000.txt b1000.txt c1000-p16.txt >> matrix_runs.txt


echo "*****serial-2000*****" >> matrix_runs.txt
./serial a2000.txt b2000.txt c2000-s.txt >> matrix_runs.txt

echo "*****parallel-1-2000*****" >> matrix_runs.txt
./parallel --threads 1 a2000.txt b2000.txt c2000-p1.txt >> matrix_runs.txt

echo "*****parallel-2-2000*****" >> matrix_runs.txt
./parallel --threads 2 a2000.txt b2000.txt c2000-p2.txt >> matrix_runs.txt

echo "*****parallel-4-2000*****" >> matrix_runs.txt
./parallel --threads 4 a2000.txt b2000.txt c2000-p4.txt >> matrix_runs.txt

echo "*****parallel-8-2000*****" >> matrix_runs.txt
./parallel --threads 8 a2000.txt b2000.txt c2000-p8.txt >> matrix_runs.txt

echo "*****parallel-16-2000*****" >> matrix_runs.txt
./parallel --threads 16 a2000.txt b2000.txt c2000-p16.txt >> matrix_runs.txt


echo "*****serial-4000*****" >> matrix_runs.txt
./serial a4000.txt b4000.txt c4000-s.txt >> matrix_runs.txt

echo "*****parallel-1-4000*****" >> matrix_runs.txt
./parallel --threads 1 a4000.txt b4000.txt c4000-p1.txt >> matrix_runs.txt

echo "*****parallel-2-4000*****" >> matrix_runs.txt
./parallel --threads 2 a4000.txt b4000.txt c4000-p2.txt >> matrix_runs.txt

echo "*****parallel-4-4000*****" >> matrix_runs.txt
./parallel --threads 4 a4000.txt b4000.txt c4000-p4.txt >> matrix_runs.txt

echo "*****parallel-8-4000*****" >> matrix_runs.txt
./parallel --threads 8 a4000.txt b4000.txt c4000-p8.txt >> matrix_runs.txt

echo "*****parallel-16-4000*****" >> matrix_runs.txt
./parallel --threads 16 a4000.txt b4000.txt c4000-p16.txt >> matrix_runs.txt


echo "*****serial-5000*****" >> matrix_runs.txt
./serial a5000.txt b5000.txt c5000-s.txt >> matrix_runs.txt

echo "*****parallel-1-5000*****" >> matrix_runs.txt
./parallel --threads 1 a5000.txt b5000.txt c5000-p1.txt >> matrix_runs.txt

echo "*****parallel-2-5000*****" >> matrix_runs.txt
./parallel --threads 2 a5000.txt b5000.txt c5000-p2.txt >> matrix_runs.txt

echo "*****parallel-4-5000*****" >> matrix_runs.txt
./parallel --threads 4 a5000.txt b5000.txt c5000-p4.txt >> matrix_runs.txt

echo "*****parallel-8-5000*****" >> matrix_runs.txt
./parallel --threads 8 a5000.txt b5000.txt c5000-p8.txt >> matrix_runs.txt

echo "*****parallel-16-5000*****" >> matrix_runs.txt
./parallel --threads 16 a5000.txt b5000.txt c5000-p16.txt >> matrix_runs.txt
