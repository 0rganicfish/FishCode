window.onload = () => {
    (() => {
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
        if (xhr.readyState === 4 && xhr.status === 200)
            document.getElementById("app").lastElementChild.innerHTML =
                xhr.responseText
    }
    let url = "ajax.php?" + str;
    /*    if (url.indexOf("?") >= 0)
            url = url + "&t=" + (new Date()).valueOf();
        else
            url = url + "?t=" + (new Date()).valueOf();
        console.log(url);
      */
    xhr.open("GET", url, true)
    xhr.send();
}

