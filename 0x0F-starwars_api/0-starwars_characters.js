#!/usr/bin/node

const request = require('request');

function getName (url) {
  return new Promise(resolve => {
    request(url, (err, response, body) => {
      if (err) {
        console.log(err);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

function getURLs () {
  return new Promise(resolve => {
    request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], (err, response, body) => {
      if (err) {
        console.log(err);
      } else {
        resolve(JSON.parse(body).characters);
      }
    });
  });
}

async function main () {
  let i;
  let result;
  const urls = await getURLs();
  for (i = 0; i < urls.length; i++) {
    result = await getName(urls[i]);
    console.log(result);
  }
}
main();
