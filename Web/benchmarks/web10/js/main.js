document.getElementById('btn').addEventListener('click', function () {
    var text = document.getElementById('inp').innerText;
    if (text[0] == 'a') {
        if (text[1] == 'b') {
            if (text.slice(-1) == 'x') {
                document.getElementById('theId').innerHTML = text;
            }
        }
    }
})