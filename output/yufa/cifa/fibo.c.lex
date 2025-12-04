    单词          词素          属性
      TYPE             int             int
        ID            fibo                
        LP               (                
      TYPE             int             int
        ID               n                
        RP               )                
    LBRACE               {                
        IF              if                
        LP               (                
        ID               n                
     RELOP              ==              ==
    NUMBER               1               1
        RP               )                
    LBRACE               {                
    RETURN          return                
    NUMBER               1               1
 SEMICOLON               ;                
    RBRACE               }                
      ELSE            else                
        IF              if                
        LP               (                
        ID               n                
     RELOP              ==              ==
    NUMBER               2               2
        RP               )                
    LBRACE               {                
    RETURN          return                
    NUMBER               2               2
 SEMICOLON               ;                
    RBRACE               }                
      TYPE             int             int
        ID               a                
    ASSIGN               =                
        ID            fibo                
        LP               (                
        ID               n                
     MINUS               -                
    NUMBER               1               1
        RP               )                
 SEMICOLON               ;                
      TYPE             int             int
        ID               b                
    ASSIGN               =                
        ID            fibo                
        LP               (                
        ID               n                
     MINUS               -                
    NUMBER               2               2
        RP               )                
 SEMICOLON               ;                
    RETURN          return                
        ID               a                
       ADD               +                
        ID               b                
 SEMICOLON               ;                
    RBRACE               }                
      TYPE             int             int
        ID            main                
        LP               (                
        RP               )                
    LBRACE               {                
      TYPE             int             int
        ID               d                
    ASSIGN               =                
        ID            fibo                
        LP               (                
    NUMBER               5               5
        RP               )                
 SEMICOLON               ;                
        ID       print_int                
        LP               (                
        ID               d                
        RP               )                
 SEMICOLON               ;                
    RBRACE               }                
