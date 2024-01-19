#include<stdlib.h>
#include<stdio.h>

int labyrinth[10][10];

typedef struct monster {
    char *name;
    const char *draw[30];
    int hp;
    int damages;
} monster_t;

void initializeWolf(monster_t *wolf)
{
    wolf->name = "Wolf";
    wolf->draw[0] = "                               __";
    wolf->draw[1] = "                             .d$$b";
    wolf->draw[2] = "                           .' TO$;\\";
    wolf->draw[3] = "                          /  : TP._;";
    wolf->draw[4] = "                         / _.;  :Tb|";
    wolf->draw[5] = "                        /   /   ;j$j";
    wolf->draw[6] = "                    _.-\"       d$$$$";
    wolf->draw[7] = "                  .' ..       d$$$$;";
    wolf->draw[8] = "                 /  /P'      d$$$$P. |\\";
    wolf->draw[9] = "                /   \"      .d$$$P' |^\"l";
    wolf->draw[10] = "              .'           `T$P^\"\"\"\"  :";
    wolf->draw[11] = "          ._.'      _.'                ;";
    wolf->draw[12] = "       `-.-\"-.-' ._.       _.-\"    .-\"";
    wolf->draw[13] = "     `.-\" _____  ._              .-\"";
    wolf->draw[14] = "    -(.g$$$$$$$b.              .'";
    wolf->draw[15] = "      \"\"^^T$$$P^)            .(:";
    wolf->draw[16] = "        _/  -\"  /.'         /:/;";
    wolf->draw[17] = "     ._.'-'`-'  \")         /;/;";
    wolf->draw[18] = "  `-.-\"..--\"\"   \" /         /  ;";
    wolf->draw[19] = " .-\"..--\"        -'          :";
    wolf->draw[20] = "..--\"--.-\"         (\\      .-(\\";
    wolf->draw[21] = "  ..--\"              `\\-(\\/;`";
    wolf->draw[22] = "     _.                      :";
    wolf->draw[23] = "                             ;`-";
    wolf->draw[24] = "                            :\\";
    wolf->draw[25] = "                            .\\";
}

void initializePhoenix(monster_t *phoenix)
{
    phoenix->name = "Phoenix";
    phoenix->draw[0] = "";
    phoenix->draw[1] = "                 (                           )";
    phoenix->draw[2] = "           ) )( (                           ( ) )( (";
    phoenix->draw[3] = "        ( ( ( )  ) )                     ( (   (  ) )(";
    phoenix->draw[4] = "       ) )     ,,\\\                     ///,,       ) (";
    phoenix->draw[5] = "    (  ((    (\\\\//                     \\////)      )";
    phoenix->draw[6] = "     ) )    (-(__//                       \\__)-)     (";
    phoenix->draw[7] = "    (((   ((-(__||                         ||__)-))    ) )";
    phoenix->draw[8] = "   ) )   ((-(-(_||           ```\\__        ||_)-)-))   ((";
    phoenix->draw[9] = "   ((   ((-(-(/(/\\        ''; 9.- `      //\\)\\)-)-))    )";
    phoenix->draw[10] = "    )   (-(-(/(/(/\\      '';;;;-\\~      //\\)\\)\\)-)-)   (   )";
    phoenix->draw[11] = " (  (   ((-(-(/(/(/\======,:;:;:;:,======/\\)\\)\\)-)-))   )";
    phoenix->draw[12] = "     )  '(((-(/(/(/(//////:%%%%%%%:\\\\\\)\\)\\)\\)-)))`  ( (";
    phoenix->draw[13] = "    ((   '((-(/(/(/('uuuu:WWWWWWWWW:uuuu`)\\)\\)\\)-))`    )";
    phoenix->draw[14] = "      ))  '((-(/(/(/('|||:wwwwwwwww:|||')\\)\\)\\)-))`    ((";
    phoenix->draw[15] = "   (   ((   '((((/(/('uuu:WWWWWWWWW:uuu`)\\)\\))))`     ))";
    phoenix->draw[16] = "         ))   '':::UUUUUU:wwwwwwwww:UUUUUU:::``     ((   )";
    phoenix->draw[17] = "           ((      '''''''\uuuuuuuu/``````         ))";
    phoenix->draw[18] = "            ))            `JJJJJJJJJ`           ((";
    phoenix->draw[19] = "              ((            LLLLLLLLLLL         ))";
    phoenix->draw[20] = "                ))         ///|||||||\\\\\\       ((";
    phoenix->draw[21] = "                  ))      (/(/(/(^)\\)\\)\\)       ((";
    phoenix->draw[22] = "                   ((                           ))";
    phoenix->draw[23] = "                     ((                       ((";
    phoenix->draw[24] = "                       ( )( ))( ( ( ) )( ) (()";
    phoenix->draw[25] = "";
}

//                            _,,,.._       ,_
//                         .gMMMMMMMMMp,_    `\
//                      .dMMP'       ``^YMb..dP
//                     dMMP'
//                     MMM:
//                     YMMb.
//                      YMMMb.
//                       `YMM/|Mb.  ,__
//                    _,,-~`--..-~-'_,/`--,,,____
//                `\,_,/',_.-~_..-~/' ,/---~~~"""`\
//           _,_,,,\q\q/'    \,,-~'_,/`````-,7.
//          `@v@`\\,,,,__   \,,-~~"__/` ",,/MMMMb.
//           `--''_..-~~\   \,-~~""  `\_,/ `^YMMMMMb..
//            ,|``-~~--./_,,_  _,,-~~'/_      `YMMMMMMMb.
//          ,/  `\,_,,/`\    `\,___,,,/M/'      `YMMMMMMMb
//                      ;  _,,/__...|MMM/         YMMMMMMMb
//                       .' /'      dMMM\         !MMMMMMMMb
//                    ,-'.-'""~~~--/M|M' \        !MMMMMMMMM
//                  ,/ .|...._____/MMM\   b       gMMMMMMMMM
//               ,'/'\/          dMMP/'   M.     ,MMMMMMMMMP
//              / `\;/~~~~----...MP'     ,MMb..,dMMMMMMMMM'
//             / ,_  |          _/      dMMMMMMMMMMMMMMMMB
//             \  |\,\,,,,___ _/    _,dMMMMMMMMMMMP".emmmb,
//              `.\  gY.     /      7MMMMMMMMMMP"..emmMMMMM
//                 .dMMMb,-..|       `.~~"""```|dMMMMP'MMP'
//                .MMMMP^"""/ .7 ,  _  \,---~""`^YMMP'MM;
// fsc          _dMMMP'   ,' / | |\ \\  }          PM^M^b
//           _,' _,  \_.._`./  } ; \ \``'      __,'_` _  `._
//       ,-~/'./'| 7`,,__,}`   ``   ``        // _/`| 7``-._`}
//      |_,}__{  {,/'   ``                    `\{_  {,/'   ``
//      ``  ```   ``                            ``   ``

void initializeDragon(type_t *dragon)
{
    dragon->name = "Dragon";
    dragon->draw[0] = "                            _,,,.._       ,_";
    dragon->draw[1] = "                         .gMMMMMMMMMp,_    `\\";
    dragon->draw[2] = "                      .dMMP'       ``^YMb..dP";
    dragon->draw[3] = "                     dMMP'                    `";
    dragon->draw[4] = "                     MMM:                      ";
    dragon->draw[5] = "                     YMMb.                     ";
    dragon->draw[6] = "                      YMMMb.                   ";
    dragon->draw[7] = "                       `YMM/|Mb.  ,__          ";
    dragon->draw[8] = "                    _,,-~`--..-~-'_,/`--,,,____";
    dragon->draw[9] = "                `\\,_,/',_.-~_..-~/' ,/---~~~\"\"\"`\\";
    dragon->draw[10] = "           _,_,,,\\q\\q/'    \\,,-~'_,/`````-,7.   ";
    dragon->draw[11] = "          `@v@`\\\\,,,,__   \\,,-~~\"__/` \",,/MMMMb.";
    dragon->draw[12] = "           `--''_..-~~\\   \\,-~~\"\"  `\\_,/ `^YMMMMMb..";
    dragon->draw[13] = "            ,|``-~~--./_,,_  _,,-~~'/_      `YMMMMMMMb.";
    dragon->draw[14] = "          ,/  `\\,_,,/`\\    `\\,___,,,/M/'      `YMMMMMMMb";
    dragon->draw[15] = "                      ;  _,,/__...|MMM/         YMMMMMMMb";
    dragon->draw[16] = "                       .' /'      dMMM\\         !MMMMMMMMb";
    dragon->draw[17] = "                    ,-'.-'\"\"~~~--/M|M' \\        !MMMMMMMMM";
    dragon->draw[18] = "                  ,/ .|...._____/MMM\\   b       gMMMMMMMMM";
    dragon->draw[19] = "               ,'/\\/'\\/          dMMP/'   M.     ,MMMMMMMMMP";
    dragon->draw[20] = "              / `\\;/~~~~----...MP'     ,MMb..,dMMMMMMMMM'";
    dragon->draw[21] = "             / ,_  |          _/      dMMMMMMMMMMMMMMMMB";
    dragon->draw[22] = "             \\  |\\,\\,,,,___ _/    _,dMMMMMMMMMMMP\".emmmb,";
    dragon->draw[23] = "              `\\. gY.     /      7MMMMMMMMMMP\".emmMMMMM";
    dragon->draw[24] = "                 .dMMMb,-..|       `.~~\"\"\"```|dMMMMP'MMP'";
    dragon->draw[25] = "                .MMMMP^\"\"\"/ .7 ,  _  \\,---~\"\"`^YMMP'MM;";
    dragon->draw[26] = " fsc          _dMMMP'   ,' / | |\\ \\  }          PM^M^b";
    dragon->draw[27] = "           _,,' _,  \\_.._`./  } ; \\ \\``'      __,'_` _  `._";
    dragon->draw[28] = "       ,-~/'./'| 7`,,__,}`   ``   ``        // _/`| 7``-._`}";
    dragon->draw[29] = "      |_,}__{  {,/'   ``                    `\\{_  {,/'   ``";
    dragon->draw[30] = "      ``  ```   ``                            ``   ``";
}