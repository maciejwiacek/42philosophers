# Philosophers - Dining Philosophers Problem
A 42 School project that solves the Dining Philosophers Problem using threads and synchronization in C. The goal is to manage concurrent execution, ensuring philosophers can alternate between eating and thinking without deadlock, by using mutexes to control access to shared resources (forks).

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Gained Knowledge](#gained-knowledge)

## Overview
The Dining Philosophers Problem is a classic concurrency problem that involves philosophers sitting at a table, alternating between eating, sleeping and thinking. They share a limited number of forks (one between each pair), and each philosopher needs two forks to eat. The challenge is to design a system where they can eat without causing deadlock (where no one can eat) or starvation (where one philosopher never gets to eat), managing resource sharing and synchronization efficiently.

## Features
- Configurable number of philosophers.
- Efficient resource handling and thread management.
- Proper error handling for thread creation, mutex initialization, and more.

## Usage
1. Clone the repository
```bash
git clone https://github.com/maciejwiacek/42philosophers.git && cd 42philosophers
```
2. Build the project
```bash
make
```
3. Run the simulation
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

## Gained Knowledge:
- Creation and magement of threads in C.
- Understanding of concurrency and synchronization.
- Insight into common problems like deadlocks and starvation in concurrent systems.
