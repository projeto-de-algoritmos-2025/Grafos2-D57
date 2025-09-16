const fs = require('fs');
const { parse } = require('node-html-parser');
const htmlContent = fs.readFileSync('./docs/ex.html', 'utf8');
const root = parse(htmlContent);
const lectureRows = root.querySelectorAll('tr.componentes');
const lectures = [];

lectureRows.forEach(row => {
  const columns = row.querySelectorAll('td');
  
  if (columns.length >= 2) {
    const code = columns[0].text.trim();
    const nameWithHours = columns[1].text.trim();
    
    const match = nameWithHours.match(/(.*) - (\d+)h/);
    
    if (match) {
      const name = match[1].trim();
      const hours = match[2];
      
      const type = columns.length >= 4 ? columns[3].text.trim() : 'N/A';
      
      const nature = columns.length >= 5 ? columns[4].text.trim() : 'N/A';
      
      lectures.push({
        code,
        name,
        hours,
        type,
        nature
      });
    }
  }
});

console.log('Found', lectures.length, 'lectures:');
console.log(JSON.stringify(lectures, null, 2));

const mandatory = lectures.filter(l => l.nature.includes('OBRIGATORIO'));
const optional = lectures.filter(l => l.nature.includes('OPTATIVO'));

console.log('\nSummary:');
console.log(`- Mandatory courses: ${mandatory.length}`);
console.log(`- Optional courses: ${optional.length}`);
