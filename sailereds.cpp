#include <stdio.h>
using namespace std;

char inp[100001];
int T, Limit;
long long int Min = 99999999999, Sx, Sy, Ex, Ey;

void Sail( int x, int y, int InChar ){
    if( x == Ex && y == Ey && InChar < Min ){
        Min = InChar;
        return;
    }
    if( InChar >= T || Limit == InChar )
        return;
    if( inp[InChar] == 'S' )
        Sail( x, y-1, InChar+1 );
    else if( inp[InChar] == 'N' )
        Sail( x, y+1, InChar+1 );
    else if( inp[InChar] == 'E' )
        Sail( x+1, y, InChar+1 );
    else if( inp[InChar] == 'W' )
        Sail( x-1, y, InChar+1 );
    Sail( x, y, InChar+1 );
}

int main(){
    scanf( "%d %lld %lld %lld %lld", &T, &Sx, &Sy, &Ex, &Ey );
    scanf( "%s", inp );
    if( ( Ex - Sx ) + ( Ey - Sy ) > T ){
        printf( "-1" );
        return 0;
    }
    for( Limit = 1; Limit <= T; Limit++ ){
        Sail( Sx, Sy, 0 );
        if( Min != 99999999999 )
            break;
    }
    if( Min != 99999999999 )
        printf( "%d", Min );
    else
        printf( "-1" );
    return 0;
}
