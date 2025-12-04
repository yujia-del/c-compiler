    单词          词素          属性
      VOID            void                
        ID            swap                
        LP               (                
      TYPE             int             int
      STAR               *                
        ID              a1                
     COMMA               ,                
      TYPE             int             int
      STAR               *                
        ID               b                
        RP               )                
    LBRACE               {                
      TYPE             int             int
        ID               t                
    ASSIGN               =                
      STAR               *                
        ID              a1                
 SEMICOLON               ;                
      STAR               *                
        ID              a1                
    ASSIGN               =                
      STAR               *                
        ID               b                
 SEMICOLON               ;                
      STAR               *                
        ID               b                
    ASSIGN               =                
        ID               t                
 SEMICOLON               ;                
    RBRACE               }                
      TYPE             int             int
        ID            main                
        LP               (                
        RP               )                
    LBRACE               {                
      TYPE             int             int
        ID               a                
    ASSIGN               =                
    NUMBER               2               2
 SEMICOLON               ;                
      TYPE             int             int
        ID               b                
    ASSIGN               =                
    NUMBER               3               3
 SEMICOLON               ;                
        ID       print_int                
        LP               (                
        ID               a                
        RP               )                
 SEMICOLON               ;                
        ID       print_int                
        LP               (                
        ID               b                
        RP               )                
 SEMICOLON               ;                
      TYPE             int             int
      STAR               *                
        ID              pa                
    ASSIGN               =                
 SINGALAND               &                
        ID               a                
 SEMICOLON               ;                
      TYPE             int             int
      STAR               *                
        ID              pb                
    ASSIGN               =                
 SINGALAND               &                
        ID               b                
 SEMICOLON               ;                
        ID            swap                
        LP               (                
        ID              pa                
     COMMA               ,                
        ID              pb                
        RP               )                
 SEMICOLON               ;                
        ID       print_int                
        LP               (                
        ID               a                
        RP               )                
 SEMICOLON               ;                
        ID       print_int                
        LP               (                
        ID               b                
        RP               )                
 SEMICOLON               ;                
    RBRACE               }                
