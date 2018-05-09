# Presenting Sounds: A new way to enjoy the music you love.

The overall time complexity of the program is O(MNlogN) 
	where N is the total number of songs in the playlist 
	and M is the number of times the user plays it.

This applies for whatever combinations of the four menu options the user chooses since the time taken for option (2) grows the fastest as the input grows.  Let's take them one at a time.

1. Load & name playlist: 
	O(N) time
2. Play playlist: 
	O(NlogN)
3. Update user information: 
	O(1) time
4. Add Song to playlist: 
	O(1) time
5. Quit: 
	O(1) time

`Load playlist` looks once at each of N songs, so it takes O(N) time.  
The `Play playlist` option sorts, then plays the playlist.  

Sorting playlist: O(NlogN)  
	We used introsort, which involves recursively halving the list.  
	In the end the list ends up being halved approximately logN times.
	The list is operated on after each halving, which takes O(N) time, 
	so the final sort runtime is O(NlogN)

The total for the `Play playlist` option is O(2N + NlogN), 
	which reduces to O(NlogN).

Everything else takes O(1) time, which has no bearing on the final logorithmic runtime once the higher order functions are factored in.  

    constructors: O(1) time  
    mutators: O(1) time  
    accessors: O(1) time  
    Playlist::AddNewSong(): O(1) time  
    User::userName(): O(1) time  
    
-->Contributions:

1. Samantha-Jo Cunningham:

    -Created the basis for the menu in main.cpp
    -Co-Created the playlist.cpp (load Playlist, playlist Name, play playlist)
    -Implement try, throw, catch statement for error handling

2. Travis Brown:

    -Co-Created the playlist.cpp (Add new song to play list, play playlist)
    -Created the getlikes function in the main.cpp

3. Peace Aku:

    -Song.cpp
    -Created the user.cpp

4. Azeezah Muhammad:

    -Figured out the time complexity for the entire program.
    -Ensures all classes work together with the main.cpp so that program requirements are achieved.
    
TRY IT: 

Files: 
main.cpp, 
user.h, 
user.cpp, 
playlist.h, 
playlist.cpp, 
song.h, 
song.cpp, 
sort.h, 
sort.cpp

Compile: $ g++ main.cpp user.cpp playlist.cpp song.cpp sort.cpp -o sounds.exe

Run: $ sounds
