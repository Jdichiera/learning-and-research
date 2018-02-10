import csv

file = open('attendees1.csv')

attendees1 = []


csv_file = csv.reader(file)

for row in csv_file:
  attendees1.append(row[2])

file.close();

file = open('attendees2.csv')

attendees2 = []


csv_file = csv.reader(file)

for row in csv_file:
  attendees2.append(row[2])

file.close();

attendees1 = set(attendees1)
attendees2 = set(attendees2)

print attendees2.difference(attendees1)
