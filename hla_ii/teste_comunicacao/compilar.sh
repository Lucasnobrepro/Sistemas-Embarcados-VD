rm run

#g++  -I. -DRTI_USES_STD_FSTREAM -I/usr/local/include/hla13 -I/usr/local/include/libhla -L/usr/local/lib  -I/home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus -I/home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../verification/tests /home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus/FederateAmbassador.cpp  /home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus/VirtualBusFederate.cpp main.cpp -o run -g -lRTI-NGd -lFedTimed -lHLAd -lCERTId

g++  -std=c++11 -I/usr/local/include/hla13 -I/home/lucas/app/certi/CERTI-master/include/hla-1_3 -I/usr/local/include/libhla -L/usr/local/lib/ -I/home/lucas/app/hla_ii/teste_comunicacao/../virtualbus -I/home/lucas/app/hla_ii/teste_comunicacao/../verification/tests -g -DRTI_USES_STD_FSTREAM -o run /home/lucas/app/hla_ii/teste_comunicacao/../virtualbus/FederateAmbassador.cpp /home/lucas/app/hla_ii/teste_comunicacao/../virtualbus/VirtualBusFederate.cpp main.cpp -lRTI-NGd -lFedTimed -lHLAd -lCERTId #`pkg-config opencv --cflags --libs`

#g++  -std=c++11 -I/usr/local/include/hla13 -I/home/werlley-ssd/app/CERTI-3.4.3-Source/include/hla-1_3 -I/usr/local/include/libhla -L/usr/local/lib/ -I/home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus -I/home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../verification/tests -g -DRTI_USES_STD_FSTREAM -o run /home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus/FederateAmbassador.cpp /home/werlley-ssd/app/verificacaoSystemC/hla_ii/teste_comunicacao/../virtualbus/VirtualBusFederate.cpp main.cpp -lRTI-NGd -lFedTimed -lHLAd -lCERTId `pkg-config opencv --cflags --libs`


#g++ -std=c++11 -I/home/felipe/Documentos/CERTI/include/hla-1_3 -L/usr/local/lib/ -g -DRTI_USES_STD_FSTREAM -o run_virtual_bus_sender FederateAmbassador.cpp VirtualBusFederate.cpp main.cpp -lRTI-NGd -lFedTimed -lHLAd -lCERTId `pkg-config opencv --cflags --libs`
