

/*
THE SERVER-SIDE: server source code
--> use Express for handling HTTP requests and serviing static files with middleware
--> limits song requests to 20 songs (maximum)
--> URLs to visit and test:
    --> http://localhost:3000 (user-friendly interface that handles index.html)
    --> http://localhost:3000/songs?title=Body+And+Soul (static file)
*/


const express = require('express'); //express framework
const http = require('http');
const PORT = process.env.PORT || 3000; //allow environment variable to possible set PORT

const app = express();

//Middleware
app.use(express.static(__dirname + '/public')); //static server

//Routes
app.get('/', (request, response) => {
  response.sendFile(__dirname + '/views/index.html');
})

app.get('/songs', (request, response) => {
  console.log(request.path);
  let songTitle = request.query.title;
  let titleWithPlusSigns = songTitle.trim().replace(/\s/g, '+');
  console.log('titleWithPlusSigns: ' + titleWithPlusSigns);

  console.log('query: ' + JSON.stringify(request.query));
  if(!songTitle) {
    //send json response to client using response.json() feature
    //of express
    response.json({message: 'Please enter Song Title'});
    return;
  }

  const options = {
    "method": "GET",
    "hostname": "itunes.apple.com",
    "port": null,
    "path": `/search?term=${titleWithPlusSigns}&entity=musicTrack&limit=20`,  //limits to 20 songs
    "headers": {
      "useQueryString": true
    }
  }

  //create the actual http request and set up
  //its handlers
  http.request(options, function(apiResponse) {
    let songData = ''
    apiResponse.on('data', function(chunk) {
      songData += chunk
    })


    apiResponse.on('end', function() {
      const allSongs = JSON.parse(songData).results;

      // Limit the number of songs to 20
      const limitedSongs = allSongs.slice(0, 20);

      // Send the limited songs to the client
      response.contentType('application/json').json({ results: limitedSongs });

    })
  }).end() 
})

//start server
app.listen(PORT, err => {
  if(err) console.log(err);
  else {
    console.log(`Server listening on port: ${PORT}`);
    console.log(`To Test:`);
    console.log(`http://localhost:3000/songs?title=Body+And+Soul`);
    console.log(`http://localhost:3000`);
  }
})
