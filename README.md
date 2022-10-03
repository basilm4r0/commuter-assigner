# Linked list commuter assigner

A system to assign commuters to buses optimally. This project reads commuter and bus information from text files and assigns commuters to buses through a terminal interface. The program is implemented through a linked list of linked lists representing each bus and its passenger.

## Usage:
  1. Create an input file named "busses.txt" in the program directory with each line in the format: ``` bus-number#departure-date#hour:minute#origin#destination#ticket-price#passenger-capacity```
  2. Create an input file named "passengers.txt" in the program directory with each line in the format: ``` student-number#departure-date#hour:minute#origin#destination```
  3. Compile the program using ```make```
  4. Run the executable.
  
## Functionality:
The program has the following functionality:
  1. Load the bus information file
  2. Load the passenger information file
  3. Assign passengers and print assignment information of all busses
  4. Print a specific bus information along with its passengers information (names and IDs)
  5. Print unmatched passengers
  6. Add new passenger
  7. Delete passenger
  8. Delete bus number
  9. Exit
