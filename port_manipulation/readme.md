Select your desired boardlibrary by altering the makro in the lib_select.h file

Port manipulation on same pin with same operation, example setting pin 13 high low high low
takes ~4.5us for one operation.
Port manipulation on a new pin takes ~15us.
Same pin other operation, for example switching pin high/low and reading its state takes ~13us -> reading takes ~9us
