Задача: Google Calendar

1. Един календар се състои от множество събития, като всяко събитие се случва на определена дата и час и има дадена продължителност (в минути).
   Всяко събитие си има и описание, а всеки календар има име (можете да използвате вградения std::string).
   
   Да се дефинират класове DateTime, Event и Calendar с подходящи член данни, конструктори, селектори и мутатори.
   За простота можете да считате, че в един календар има не повече от 20 събития.

   Да се дефинират отделни заглавни файлове за всеки клас.

   Можете да разширите класа Date от предното упражнение да съдържа и момент във времето.
 
1. Да се добави метод Calendar::addEvent(Event event), който добавя събитие към календара.

1. Да се добави метод DateTime Event::getEnd(), който изчислява кога ще приключи даденото събитие. 
   За целта да се дефинира публичен метод DateTime::add(unsigned minutes), който прибавя дадения брой минути към съответния момент.

1. Да се добави метод Event Calendar::getLastEvent(), който намира събитието в календара, приключващо последно.
   За целта да се дефинира публичен метод int DateTime::compare(const DateTime& other), който сравнява два момента във времето.
   
1. Да се реализира програма, която създава календар с въведено от клавиатурата име,
   след което добавя няколко събития в него и намира кое от тях ще приключи последно.
