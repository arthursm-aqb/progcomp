#include <iostream>

/*Vinicius is at a board meeting of the "Instituto de Consultoria de Palestras e Comentários" (ICPC) thinking that it would be great if the board members were more concise and kept their speeches within the time allotted for each director, so that the meeting could end before lunch.
*Unfortunately, perhaps due to the nature of the institution, everyone loves to talk.
*Knowing that:
*
* -there are N
* -directors who will speak at the meeting;
* -each director will speak for the same amount of time;
* -and that between two consecutive speeches there is a 1-minute interval,
*
*determine the maximum length of each speech, in minutes, so that the meeting lasts no more than K
*minutes.
*Input:
*The first line contains an integer N(1≤N≤100), the number of directors. The second line contains an integer K(1≤K≤1000 and K≥N), the maximum meeting duration in minutes. For all input cases, each director's speech lasts at least 1 minute.
*
*Output:
*Your program should output a single line, containing a single integer, indicating the length of each board member's speech, in minutes.
*/

int main() {

    int diretores; std::cin >> diretores; /*Input the number of directors*/
    int mReuniao; std::cin >> mReuniao; /*Input the maximum meeting time.*/
    mReuniao = (((60 * mReuniao)-((diretores-1)*60))/60)/diretores;  /*Here we calculate the net value of the meeting by subtracting the time lost during breaks between consecutive speeches, represented by (60 * mReuniao) - ((diretores-1) * 60),
    then the total net time is converted from seconds to minutes and divided by the number of directors.*/
    std::cout << mReuniao; /*Output of the total number of speeches for each director*/

    return 0;
}
