var upname = document.getElementsByClassName("bili-dyn-title"),
	up = new Set()

upname.forEach((element) => {
	up.add(element.innerText)
})

console.log("共有", up.size, "位 up 主更新了动态。分别是：")
up.forEach((element) => {
	console.log(element)
})
