;(() => {
  let httpRequest
  document.getElementById("ajaxButton").addEventListener("click", makeRequest)

  function makeRequest() {
    httpRequest = new XMLHttpRequest()
    if (!httpRequest) {
      alert("Giving up :( Cannot create an XMLHTTP instance")
      return false
    }
    httpRequest.onreadystatechange = alertContents
    httpRequest.open("GET", "fish.html")
    httpRequest.send()
  }

  function alertContents() {
    if (httpRequest.readyState === XMLHttpRequest.DONE)
      if (httpRequest.status === 200) alert("request is 200")
      else alert("There was a problem with the request.")
  }
})()
