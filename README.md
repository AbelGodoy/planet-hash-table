# planet-hash-table

This Program implements a hash table system in C++ that can effectively organize aaand search large data sets


Features:
Custom Hash table
Polynomial hash functions
Collision Handlind using linked list chaining
Planet Search by name
CSV Dataset
Graph algorithms
BFS
DFS

Concepts:
OOP
Data Structures
Hash tables
Graphs
CSV



Example:
===========================================
     NASA Exoplanet Search System
===========================================

Loading exoplanet data from CSV file...
Successfully loaded 35099 planet records.

=== Hash Table Statistics ===
Table Size: 1009
Total Items: 35099
Used Buckets: 1003
Load Factor: 34.7859
Max Chain Length: 93
Average Chain Length: 34.994
=============================

Enter a planet name to search: 17 sco b

Found 1 record(s) for '17 sco b':
----------------------------------------
Planet Name: 17 Sco b
Number of Stars: 1
Number of Planets: 1
Discovery Method: Radial Velocity
Discovery Year: 2020
Discovery Facility: Lick Observatory
Orbital Period (days): 578.38
Planet Mass (Earth Mass): 1373.02
Stellar Temperature (K): 4157.00
Stellar Radius (Solar Radius): 25.92
Stellar Mass (Solar Mass): 1.22
Stellar Surface Gravity (log10): 1.70
Distance (pc): 124.95
----------------------------------------

Would you like to search for another planet? (y/n): n

Thank you for using the Exoplanet Search System!



How it works:
The planet data that is outputted is loaded from a CSV data set. Each planet is then loaded into a custom cash map and a polynomial hash function calculates the bucket index.
Users search planets by name the system retrieves and displays matching records.


Author:
Abel Godoy
