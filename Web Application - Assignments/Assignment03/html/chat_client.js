
/*
Deneo Shi 101271921

Client-side javascript code (reachable at `chat_client.js` by both the client-side html and the server-side)

Functionality: 
1. onmessage logics
  --> whenever a message is sent to the server, then apply CSS styling
2. connect() logics
  --> if the username is valid, then enable chatting 
  function calls:
    --> validUsername(): to test if the username is valid
    --> enableChat(): to enable the "send button" and "message box" to let users chat with web browser
3. sendmessage() logics
  --> handles all types of messaging: public, private, and group (delegates {username} and {message} to the server)
  function calls:
    --> addPublicMessage(): to directly print onto the sender client page (server handles other clients)
    --> addPrivateMessage(): same as addPublicMessage() but using red CSS styling instead of black
4. addPublicMessages() logics
5. addPrivateMessage() logics
6. enableChat() logics
  --> the intial source code has both the "send button" and the "message box" as disabled, enable chat enables them
7. displayConnectedMessages() logics
  --> displays a message onto the client page when the "connect_button" is pressed (to ackowledge success)
8. event handlers logics
  --> handles for:
    --> send_button : when the send button is clicked, sendMessage() is called
    --> connect_button : when the connect button is clicked, connect() is called
    --> enter_key : if the enter key is pressed, then sendMessage() is called (same functionality as send_button)
    --> clear_button : if the clear button is clicked, then simply clear the current client's page
*/


//connect to web socket server at the
//same host that provided the webpage
const url = 'ws://' + window.document.location.host
console.log('ws url: ' + url)
let ws = new WebSocket(url)

ws.addEventListener('open', function(event) {
  console.log('WebSocket Connection Opened:', event);
});


// Disable input and send button (for the start of code)
document.getElementById('msgBox').disabled = true;
document.getElementById('send_button').disabled = true;


// whenever a message is sent to the server, then apply CSS styling
ws.onmessage = function(event) {
  let isJson = true;
  let parsedMessage = null;

  try {
      parsedMessage = JSON.parse(event.data);
  } catch (error) {
      // Handle non-JSON messages (plain text)
      isJson = false;
  }

  if (isJson && parsedMessage) {
    // Handle JSON messages
    const username = parsedMessage.username;
    let content = parsedMessage.message;
    let isPrivate = false;
    let isGroupPrivate = false;

    // Check if the message is private or group private
    if (content.startsWith('(private)')) {
        isPrivate = true;
        content = content.substring('(private)'.length).trim(); // Remove the private message prefix
    } else if (content.startsWith('(private)')) {
        isGroupPrivate = true;
        content = content.substring('(private)'.length).trim(); // Remove the group private message prefix
    }

    const msgDiv = document.createElement('div');

    msgDiv.textContent = username + ': ' + content;

    // Add custom attribute based on message type (private/public/group private)
    if (isPrivate) {
        msgDiv.setAttribute('data-message-type', 'private');
    } else if (isGroupPrivate) {
        msgDiv.setAttribute('data-message-type', 'group-private');
    } else {
        msgDiv.setAttribute('data-message-type', 'public');
    }

    // Set color based on message type (private and group private messages in red)
    if (username === document.getElementById('username').value) {
        msgDiv.setAttribute('data-sender', 'me');
    } else {
        msgDiv.setAttribute('data-sender', 'others');
        if (isPrivate || isGroupPrivate) {
            msgDiv.style.color = 'red';
        }
    }

      document.getElementById('messages').appendChild(msgDiv);
  } else {
      // Handle non-JSON messages (plain text)
      let textDiv = document.createElement('div');
      textDiv.textContent = event.data;
      document.getElementById('messages').appendChild(textDiv);
  }
};



// modularity functions:

// Enable input and send button after successful connection
function enableChat() {
  document.getElementById('msgBox').disabled = false;
  document.getElementById('send_button').disabled = false;
}

// if the username is valid, then enable chatting 
function connect() {
  const username = document.getElementById('username').value;
  if (isValidUsername(username) ) {
    enableChat();
    if (username.replace(/\s/g, '').length) {
      displayConnectedMessage(username);
    }
  }
}

//testing if valid username
function isValidUsername(username) {
  const regex = /^[a-zA-Z][a-zA-Z0-9]*$/;
  if (!username.replace(/\s/g, '').length) {
    console.log('string only contains whitespace (ie. spaces, tabs or line breaks)');
    // return null;
  }
  else{
    return regex.test(username);
  }
}

// displays a message onto the client page when the "connect_button" is pressed (to ackowledge success)
function displayConnectedMessage(username) {
  const msgDiv = document.createElement('div');
  msgDiv.textContent = 'Connected as ' + username;
  document.getElementById('messages').appendChild(msgDiv);
}

// handles all types of messaging: public, private, and group (delegates {username} and {message} to the server)
function sendMessage() {
  const message = document.getElementById('msgBox').value;
  const username = document.getElementById('username').value;
  const privateMessageRegex = /^([a-zA-Z][a-zA-Z0-9]*):\s*(.+)$/;

  if (privateMessageRegex.test(message)) {
      const matches = message.match(privateMessageRegex);
      const targetUser = matches[1];
      const privateMessage = matches[2];

      if (isValidUsername(targetUser)) {
          // Send the private message as a JSON object
          ws.send(JSON.stringify({ username: username, message: `(private) ${privateMessage}` })); //////////////////////////////////////
          // ws.send(JSON.stringify({ username: username, message: `(private) ${targetUser}: ${privateMessage}` })); //////////////////////////////////////

          addPrivateMessage(username, privateMessage);
      } else {
          // invalid target username
          console.log('Invalid username spotted (chat_client.js)');
      }
  } else {
      // to match group private messages
      const groupPrivateMessageRegex = /^(\w+(,\s*\w+)*):\s*(.+)$/;

      if (groupPrivateMessageRegex.test(message)) {
          const matches = message.match(groupPrivateMessageRegex);
          const recipients = matches[1].split(',').map(name => name.trim());
          const groupMessage = matches[3];

          if (isValidUsername(username)) {
            ws.send(JSON.stringify({ username: username, message: `(private) ${groupMessage}` })); //////////////////////////////////////
            // ws.send(JSON.stringify({ username: username, message: `(private) ${recipients}: ${groupMessage}` })); //////////////////////////////////////
            addPrivateMessage(username, groupMessage);
          } else {
              // Handle invalid username
              console.log('Invalid username spotted (chat_client.js)');
          }
      } else {
          // Public message, send to all users
          if (isValidUsername(username)) {
              // Send the public message as a JSON object
              ws.send(JSON.stringify({ username: username, message: message }));
              addPublicMessage(username, message);
          } else {
              // Handle invalid username
              console.log('Invalid username spotted (chat_client.js)');
          }
      }
  }

  document.getElementById('msgBox').value = '';
}

// to directly print onto the sender client page (server handles other clients)
function addPublicMessage(username, message) {
  const msgDiv = document.createElement('div');
  msgDiv.textContent = username + ': ' + message;

  if (username === document.getElementById('username').value) {
    msgDiv.style.color = 'blue'; // Own messages in blue
  } else {
    msgDiv.style.color = 'black'; // Other users' messages in black
    if (isPrivate) {
        msgDiv.style.color = 'red'; // Private messages in red
    }
  }
  document.getElementById('messages').appendChild(msgDiv);
}

// same as addPublicMessage() but using red CSS styling instead of black
function addPrivateMessage(username, message) {
  const msgDiv = document.createElement('div');
  msgDiv.textContent = username + ': ' + message;
  msgDiv.style.color = 'red'; // Set color to red for private messages
  document.getElementById('messages').appendChild(msgDiv);
}


//Add event handlers to html document
document.addEventListener('DOMContentLoaded', function() {

  document.getElementById('send_button').addEventListener('click', sendMessage)

  document.getElementById('connect_button').addEventListener('click', connect)

  document.getElementById('msgBox').addEventListener('keydown', function(event) {
    if (event.key === 'Enter') {
      sendMessage();
    }
  });

  document.getElementById('clear_button').addEventListener('click', function() {
    document.getElementById('messages').innerHTML = '';
  });
})

