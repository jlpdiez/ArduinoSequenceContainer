// #############################################################################
// #
// # Name       : Sequence Container Example
// # Version    : 1.0
// # Author     : Juan L. Perez Diez <ender.vs.melkor at gmail>
// # Date       : 31.10.2016
//
// # Description: Implements a dynamic sequence container
// 			      Iteration and access is made by moving a "Point of Interest" forward
//
// #  This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// #############################################################################

#include "Arduino.h"
#include "Sequence.h"

//Iteration example
void printSequence(CSequence<uint8_t>& seq) {
  for (seq.restart(); !seq.isEnd(); seq.forward()) {
    Serial.print(seq.actual());
    Serial.print(",");
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);

	
  Serial.println(".::[ SEQUENCE.H TESTS & EXAMPLE USAGE ]::.");
  Serial.println();
  CSequence<uint8_t> seq;
  Serial.println("Created sequence");

  //Add
  Serial.println("##### ADD DATA #####");
  for (uint8_t i = 0; i < 25; i++) {
    seq.add(i);
  }
  printSequence(seq);  Serial.println();

  //Remove by reference
  Serial.println("##### REMOVE BY REFERENCE #####");
  Serial.println("del 2");
  seq.remove(2);
  printSequence(seq);  
  Serial.println("del 24");
  seq.remove(24);
  printSequence(seq);  
  Serial.println("del 9");
  seq.remove(9);
  printSequence(seq);  
  Serial.println("del 10");
  seq.remove(1540);
  printSequence(seq);  
  Serial.println("del -1");
  seq.remove(-1);
  printSequence(seq);  
  Serial.println("del 0");
  seq.remove(0);
  printSequence(seq);  
  Serial.println("del 0");
  seq.remove(0);
  printSequence(seq);  
  Serial.println();

  //Test find algorithm deleting
  Serial.println("##### FIND BY REFERENCE #####");
  Serial.print("Found8?: ");
  boolean result = seq.find(8);
  Serial.println(result);
  Serial.print(" proof: ");
  Serial.println(seq.actual());
  Serial.print("Found6?: ");
  result = seq.find(6);
  Serial.println(result);
  Serial.print(" proof: ");
  Serial.println(seq.actual());
  Serial.print("Found10?: ");
  result = seq.find(10);
  Serial.println(result);
  Serial.print(" proof: ");
  Serial.println(seq.actual());
  Serial.print("Found10?: ");
  result = seq.find(-1);
  Serial.println(result);
  Serial.print(" proof: ");
  Serial.println(seq.actual());
  Serial.println();

  //Test reversing
  Serial.println("##### REVERSE SEQUENCE #####");
  seq.reverse();
  Serial.print("Flip: ");
  printSequence(seq);  seq.reverse();
  Serial.print("Flip: ");
  printSequence(seq);  Serial.println();

  //Test getByPos
  Serial.println("##### GET BY INDEX #####");
  Serial.print("Get 0: ");
  Serial.println(seq.getByPos(0));
  Serial.print("Get 1: ");
  Serial.println(seq.getByPos(1));
  Serial.print("Get 2: ");
  Serial.println(seq.getByPos(2));
  Serial.print("Get 3: ");
  Serial.println(seq.getByPos(3));
  Serial.print("Get 4: ");
  Serial.println(seq.getByPos(4));
  Serial.print("Get numElems-1 [");
  Serial.print(seq.numElems()-1);
  Serial.print("]: ");
  Serial.println(seq.getByPos(seq.numElems()-1));
  Serial.print("Get numElems [");
  Serial.print(seq.numElems());
  Serial.print("]: ");
  Serial.println(seq.getByPos(seq.numElems()));
  Serial.print("Get numElems+15 [");
  Serial.print(seq.numElems()+15);
  Serial.print("]: ");
  Serial.println(seq.getByPos(seq.numElems()+15));
  Serial.println();

  //Iterates using isEmpty() as condition and deletes
  Serial.println("##### ITERATES DELETING ALL #####");
  seq.restart();
  Serial.print("numElems: ");
  Serial.println(seq.numElems());
  while (!seq.isEmpty()) {
  	Serial.print("del ");
    Serial.print(seq.actual());
    Serial.print(" # ");
    seq.del();
  }
  Serial.println();
  Serial.print("numElems: ");
  Serial.println(seq.numElems());
  printSequence(seq);

  Serial.println("##### THAT'S ALL FOLKS! #####");
}

void loop() {
	delay(100);
}