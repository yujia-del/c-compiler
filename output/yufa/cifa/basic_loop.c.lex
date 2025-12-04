    单词          词素          属性
      TYPE             int             int
        ID            main                
        LP               (                
        RP               )                
    LBRACE               {                
      TYPE             int             int
        ID               a                
     COMMA               ,                
        ID               b                
    ASSIGN               =                
    NUMBER               1               1
 SEMICOLON               ;                
      TYPE             int             int
        ID               c                
    ASSIGN               =                
    NUMBER               3               3
 SEMICOLON               ;                
        ID               a                
    ASSIGN               =                
        ID               b                
       ADD               +                
        LP               (                
    NUMBER              10              10
       DIV               /                
    NUMBER               2               2
        RP               )                
     POWER               ^                
    NUMBER               3               3
 SEMICOLON               ;                
        IF              if                
        LP               (                
        ID               a                
     RELOP              !=              !=
    NUMBER               0               0
        RP               )                
    LBRACE               {                
        ID       print_int                
        LP               (                
        ID               a                
        RP               )                
 SEMICOLON               ;                
     WHILE           while                
        LP               (                
        ID               a                
     RELOP               <               <
    NUMBER              10              10
       AND              &&                
        ID               b                
     RELOP               <               <
    NUMBER              10              10
        RP               )                
    LBRACE               {                
        ID       print_int                
        LP               (                
        ID               a                
        RP               )                
 SEMICOLON               ;                
        ID               a                
    ASSIGN               =                
        ID               a                
      STAR               *                
        ID               b                
      STAR               *                
        ID               c                
 SEMICOLON               ;                
        ID               b                
    ASSIGN               =                
        ID               b                
       MOD               %                
    NUMBER               2               2
 SEMICOLON               ;                
    RBRACE               }                
       FOR             for                
        LP               (                
      TYPE             int             int
        ID               i                
    ASSIGN               =                
    NUMBER               0               0
 SEMICOLON               ;                
        ID               i                
     RELOP               <               <
    NUMBER               1               1
 SEMICOLON               ;                
        ID               i                
    ASSIGN               =                
    NUMBER               1               1
       ADD               +                
        ID               i                
        RP               )                
    LBRACE               {                
        ID               i                
    ASSIGN               =                
        ID               b                
       ADD               +                
        ID 