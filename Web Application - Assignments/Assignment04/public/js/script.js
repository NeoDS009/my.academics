
/*
THE CLIENT-SIDE: JavaScript source code
--> event listeners: 
    >>> whenever a button is clicked, the closest song's trackName will be located,
        and depending on which button is clicked:
    --> removeSong() 
        --> will remove the song from the playlist
    --> moveSongUp() 
        --> will switch position with song that is before it
    --> moveSongDown() 
        --> will switch position with song that comes after it
    --> addSongToPlaylist()
        --> will add a song to the `playlist` from the searchPlaylist results
    >>> furthemore, after any button eventListener's action is performed, the updatePlaylist()
        will then be called to update any applied changes

--> XMLHttpRequest for making API requests for songs

--> DOM Manipulation: 
    >>> here are the functions that directly affect the client's browser view
    --> createSongRow()
        --> whenever this function is called, a row with columns of {buttons, trackName, 
          artistName, artWorkUrl100} is created. The buttons are created 'on-the-spot' within
          this function, instead of within the html part of the client-side code. Moreover, 
          the buttons, row attributes and components are all linked to a specific CSS styling.
    --> updatePlaylist()
        --> whenever this function is called, clear the playlist's table, and repopulate it
    --> updateSearchResult()
        --> whenever this function is called, clear the search-result's table, and repopulate it
    --> getSong()
        --> getting a song from the server-side

--> Local Storage: 
    --> savePlaylistToLocalStorage()
        --> function that saves onto the `local storage` the JSON object of a playlist
*/


/*
DOM Manipulation: 
    >>> here are the functions that directly affect the client's browser view
    --> all of the functions located afterwards are briefly explained previously (above)
    --> each function has minimal comments to avoid overpopulating the code or corrutping readability,
        each comment has been placed to indicate an important step of the function
*/
document.addEventListener('DOMContentLoaded', function () {

  function createSongRow(song, isPlaylist) {
    const row = document.createElement('tr');
  
    row.dataset.title = song.trackName;
  
    // Create buttons column
    const buttonsCell = document.createElement('td');
    if (isPlaylist) {
      const removeButton = document.createElement('button');
      removeButton.textContent = '➖';
      buttonsCell.appendChild(removeButton);
  
      const upButton = document.createElement('button');
      upButton.textContent = '🔼';
      buttonsCell.appendChild(upButton);
  
      const downButton = document.createElement('button');
      downButton.textContent = '🔽';
      buttonsCell.appendChild(downButton);
    } else {
      const addButton = document.createElement('button');
      addButton.textContent = '➕';
      addButton.addEventListener('click', () => addSongToPlaylist(song));
      buttonsCell.appendChild(addButton);
    }
  
    // Add buttons column to the row
    row.appendChild(buttonsCell);

    // Add title, artist, and image columns
    const columns = ['trackName', 'artistName', 'artworkUrl100'];
    columns.forEach(column => {
      const cell = document.createElement('td');
      if (column === 'artworkUrl100') {
        const img = document.createElement('img');
        img.src = song[column];
        cell.appendChild(img);
      } else {
        cell.textContent = song[column];
      }
      row.appendChild(cell);
    });

    // Add buttons column to the row with the specified class
    buttonsCell.classList.add('buttons-cell');

    return row;
  }
    

  function updatePlaylist(playlistData) {
    const playlistBody = document.getElementById('playlist_body');
    playlistBody.innerHTML = ''; // Clear the table
  
    // Ensure playlistData has the correct structure
    const playlist = playlistData.playlist || [];
    console.log('Current Playlist:', playlist);
  
    playlist.forEach(song => {
      const row = createSongRow(song, true);
      playlistBody.appendChild(row);
    });
  }
  

  function updateSearchResults(searchResults) {
    const searchResultsBody = document.getElementById('search_results_body');
    searchResultsBody.innerHTML = ''; // Clear the results
  
    searchResults.forEach(song => {
      const row = createSongRow(song, false);
      searchResultsBody.appendChild(row);
    });
  }
  

  function addSongToPlaylist(song) {
    const playlistData = JSON.parse(localStorage.getItem('playlist')) || { playlist: [], expiration: 0 };
    let playlist = playlistData.playlist;
  
    // Ensure playlist is an array
    if (!Array.isArray(playlist)) {
      playlist = [];
    }
  
    playlist.push(song);
    updatePlaylist({ playlist });
    savePlaylistToLocalStorage({ playlist, expiration: playlistData.expiration });
  }
  

  function removeSong(song) {
    const playlistData = JSON.parse(localStorage.getItem('playlist')) || { playlist: [], expiration: 0 };
    let playlist = playlistData.playlist;
  
    // Ensure playlist is an array
    if (!Array.isArray(playlist)) {
      playlist = [];
    }
  
    const index = playlist.findIndex(item => item.trackName === song.trackName);
  
    if (index !== -1) {
      playlist.splice(index, 1); // Remove 1 element at the found index
      updatePlaylist({ playlist });
      savePlaylistToLocalStorage({ playlist, expiration: playlistData.expiration });
    }
  }
  


  function moveSongUp(song) {
    const playlistData = JSON.parse(localStorage.getItem('playlist')) || { playlist: [], expiration: 0 };
    let playlist = playlistData.playlist;

    // Ensure playlist is an array
    if (!Array.isArray(playlist)) {
      playlist = [];
    }

    const index = playlist.findIndex(item => item.trackName === song.trackName);

    if (index > 0) {
      const temp = playlist[index];
      playlist[index] = playlist[index - 1];
      playlist[index - 1] = temp;

      updatePlaylist({ playlist });
      savePlaylistToLocalStorage({ playlist, expiration: playlistData.expiration });
    }
  }

  function moveSongDown(song) {
    const playlistData = JSON.parse(localStorage.getItem('playlist')) || { playlist: [], expiration: 0 };
    let playlist = playlistData.playlist;

    // Ensure playlist is an array
    if (!Array.isArray(playlist)) {
      playlist = [];
    }

    const index = playlist.findIndex(item => item.trackName === song.trackName);

    if (index < playlist.length - 1 && index !== -1) {
      const temp = playlist[index];
      playlist[index] = playlist[index + 1];
      playlist[index + 1] = temp;

      updatePlaylist({ playlist });
      savePlaylistToLocalStorage({ playlist, expiration: playlistData.expiration });
    }
  }


  // Function to get song data from the server
  function getSong() {
    const songTitle = document.getElementById('songTitleTextField').value.trim();

    if (!songTitle) {
      return alert('Please enter a Song Title');
    }

    const xhr = new XMLHttpRequest();

    xhr.onreadystatechange = () => {
      if (xhr.readyState === 4) {
        if (xhr.status === 200) {
          const response = JSON.parse(xhr.responseText);
          const searchResults = response.results;
    
          const searchResultsHeading = document.getElementById('search_results_heading');
          searchResultsHeading.textContent = `Songs matching: ${songTitle}`;
    
          updateSearchResults(searchResults);
        } else {
          console.error('Error fetching song data:', xhr.statusText);
        }
      }
    };
    

    xhr.open('GET', `/songs?title=${songTitle}`, true);
    xhr.send();
  }

  // Attach event listeners
  document.getElementById('submit_button').addEventListener('click', getSong);
  document.addEventListener('keyup', (event) => {
    event.preventDefault();
    if (event.keyCode === 13) {
      document.getElementById('submit_button').click();
    }
  });


  // Event listeners for buttons in the playlist area
  document.getElementById('playlist_table').addEventListener('click', (event) => {

    const button = event.target;

    // Check if the clicked element is a button
    if (button.tagName === 'BUTTON') {
      const songRow = button.closest('tr');
      const songTitle = songRow.dataset.title;

      const song = {
        trackName: songTitle,
      };

      if (button.textContent === '➖') {
        removeSong(song);
      } else if (button.textContent === '🔼') {
        moveSongUp(song);
      } else if (button.textContent === '🔽') {
        moveSongDown(song);
      } else if (button.textContent === '➕') {
        addSongToPlaylist(song);
      }
    }

  });


  // Load playlist from local storage
  const storedPlaylist = JSON.parse(localStorage.getItem('playlist')) || [];
  updatePlaylist(storedPlaylist);

  // Function to save the playlist to local storage
  function savePlaylistToLocalStorage(playlist) {
    localStorage.setItem('playlist', JSON.stringify(playlist));    
  }

});

