window.onload = () => {
  ;(() => {
    document.getElementById("play").addEventListener("click", () => {
      Ajax("sel=play")
    })
    document.getElementById("close").addEventListener("click", () => {
      Ajax("sel=close")
    })
  })()
}

function Ajax(str) {
  let xhr = new XMLHttpRequest()
  xhr.onreadystatechange = () => {
    // console.log(xhr.readyState, xhr.status, str);
    if (xhr.readyState === 4 && xhr.status === 200)
      document.getElementById("app").lastElementChild.innerHTML =
        xhr.responseText
  }
  xhr.open("GET", "ajax.php?" + str, true)
  xhr.send()
}
